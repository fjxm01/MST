**MST 함수 사용법**

1. 입력 형태
  - 입력: PCL의 Type PointXYZ를 입력

2. 옵션 설정
  - MSTResult MST(cloud, compactnessThreshold = (0.5F), MSTAlgorithm algo = MSTAlgorithm::kruskal)
  - compactnessThreshold: MST로 얻은 주요 그룹이 얼마나 퍼져 있어야 유효한 그룹으로 간주할지를 결정하는 값 (간선 거리 제한)
  - MSTAlgorithm algo: MST 방법론 종류인 kruskal방식과 Prim 방식을 결정할 수 있다. 

3. 함수 사용

  1) MSTResult result = MST(downsampledCloud)와 같이 실생 후 MST의 result 값을 얻어온다. (finalGroups, mstEdges, longestPathEdges)
     - finalGroups: 최종 필터링된 그룹
     - mstEdges: 전체 MST 연결 간선
     - longestPathEdges: 최장 경로 기반 간선
  2) MST 시각화
     PC_viz에서 MST시각화 함수를 불러와서 위에 MST result값을 입력 후 시각화 한다.
     - viz.MST(downsampledCloud, result.finalGroups, result.mstEdges, result.longestPathEdges, opt);

  <img width="962" height="572" alt="image" src="https://github.com/user-attachments/assets/7ef00dc6-a577-458d-962c-32cec9c54bb2" />

**MST 기법 성명**
  -
정의)

주어진 undirected connected graph에서 모든 정점을 최소 비용으로 연결하는 트리구조이다.
이러한 트리 구조를 만들기 위한 조건이 있으며 그 조건은 다음과 같으 3가지로 나눌 수 있다. 
1) 사이클이 없어야 한다. 
2) 모든 노드가 연결되어 있어야 한다. 
3) 간선 가중치의 총합이 최소가 되어야 한다. 

알고리즘 순서)

**Prim MST)**

<img width="1060" height="591" alt="image" src="https://github.com/user-attachments/assets/e665e253-fd92-4278-9ce9-1cecda79bfe6" />
<img width="1159" height="504" alt="image" src="https://github.com/user-attachments/assets/715b1232-fbcf-4221-a4f7-bfcddb067e9a" />

**Kruskal MST)** 

<img width="1141" height="569" alt="image" src="https://github.com/user-attachments/assets/456b8ddd-c285-4e20-97ca-3d527cd29723" />
<img width="1075" height="522" alt="image" src="https://github.com/user-attachments/assets/03df8921-f2e8-4b56-9adb-56d5ec96e1b5" />



