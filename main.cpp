#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/common/common.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/visualization/pcl_visualizer.h>
#include "mst/mst.h"
#include "viz/PC_viz.h"

int main(int argc, char **argv)
{
    std::filesystem::path folderPath = std::filesystem::current_path() / "data" / "PCD";
    std::vector<std::string> Files;

    // PCD 파일 수집
    for (const auto &entry : std::filesystem::directory_iterator(folderPath))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".pcd")
            Files.push_back(entry.path().string());
    }

    if (Files.empty())
    {
        std::cerr << "No PCD files found in: " << folderPath << std::endl;
        return -1;
    }

    for (const auto &file : Files)
    {
        std::cout << "Processing: " << file << std::endl;
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());
        if (pcl::io::loadPCDFile(file, *cloud) == -1)
        {
            PCL_ERROR("Failed to load: %s\n", file.c_str());
            continue;
        }

        // 다운샘플링
        pcl::PointCloud<pcl::PointXYZ>::Ptr downsampledCloud(new pcl::PointCloud<pcl::PointXYZ>());
        pcl::VoxelGrid<pcl::PointXYZ> voxelGrid;
        voxelGrid.setInputCloud(cloud);
        voxelGrid.setLeafSize(0.01f, 0.01f, 0.01f);
        voxelGrid.filter(*downsampledCloud);

        // MST 수행
        MSTResult result = MST(downsampledCloud, 0.1f, MSTAlgorithm::kruskal);

        // 시각화
        Base3DViz viz;
        Base3DViz::PCOptions opt;
        opt.name = "MST Visualization";
        opt.pointSize = 2.0f;
        opt.centerCamera = true;
        opt.showCentroid = true;
        viz.MST(downsampledCloud, result.finalGroups, result.mstEdges, result.longestPathEdges, opt);
    }

    return 0;
}
