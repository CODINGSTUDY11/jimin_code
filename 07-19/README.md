#1697 숨바꼭질     
해당 문제는 BFS를 사용하는 문제이다.   


bfs의 특징   
직관적이지 않은 면이 있다.     
BFS는 시작 노드에서 시작해서 거리에 따라 단계별로 탐색한다고 볼 수 있다.    
BFS는 재귀적으로 동작하지 않는다.            
이 알고리즘을 구현할 때 가장 큰 차이점은, 그래프 탐색의 경우 어떤 노드를 방문했었는지 여부를 반드시 검사 해야 한다는 것이다.            
이를 검사하지 않을 경우 무한루프에 빠질 위험이 있다.         
BFS는 방문한 노드들을 차례로 저장한 후 꺼낼 수 있는 자료 구조인 큐(Queue)를 사용한다.           
즉, 선입선출(FIFO) 원칙으로 탐색             
일반적으로 큐를 이용해서 반복적 형태로 구현하는 것이 가장 잘 동작한다.              

시간 복잡도    
인접 리스트로 표현된 그래프: O(N+E)           
인접 행렬로 표현된 그래프: O(N^2)          
깊이 우선 탐색(DFS)과 마찬가지로 그래프 내에 적은 숫자의 간선만을 가지는 희소 그래프(Sparse Graph) 의 경우 인접 행렬보다 인접 리스트를 사용하는 것이 유리하다.


#1753_최단경로        
