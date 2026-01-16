#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
using namespace std;



class Graph{
    vector <vector<int>> adj_matrix;
    public:
        Graph(int n){
            adj_matrix = vector<vector<int>>(n, vector<int>(n, 0));
        }//constructor
        void addEdge(int u, int v){
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1;
        }

        void bfs(int source, vector <int> &visitedProvince){
            bool isVisited[12];
            memset(isVisited, false, sizeof(isVisited));
            queue <int> q;
            q.push(source);
            isVisited[source] = true;
            visitedProvince.push_back(source);
            while(!q.empty()){
                int vertice = q.front();
                q.pop();
                for(int i = 1; i <= 11; ++i){
                    if(!isVisited[i] && adj_matrix[vertice][i] == 1){
                        visitedProvince.push_back(i);
                        q.push(i);
                        isVisited[i] = true;
                    }
                }
            }
            return ;
        }
};

int main(){
    string arr[11];
    Graph ProvinceRoad(12);
    vector <int> visitedProvince;
    queue <int> q;
    arr[0] = "Ha Noi";
    arr[1] = "Hai Duong";
    arr[2] = "Hai Phong";
    arr[3] = "Uong Bi";
    arr[4] = "Bac Giang";
    arr[5] = "Bac Ninh";
    arr[6] = "Thai Nguyen";
    arr[7] = "Son Tay";
    arr[8] = "Hoa Binh";
    arr[9] = "Phu Ly";
    arr[10] = "Hung Yen";
    ProvinceRoad.addEdge(1, 2);
    ProvinceRoad.addEdge(1, 6);
    ProvinceRoad.addEdge(1, 7);
    ProvinceRoad.addEdge(1, 8);
    ProvinceRoad.addEdge(1, 9);
    ProvinceRoad.addEdge(1, 10);
    ProvinceRoad.addEdge(10, 11);
    ProvinceRoad.addEdge(11, 2);
    ProvinceRoad.addEdge(2, 3);
    ProvinceRoad.addEdge(3, 4);
    ProvinceRoad.addEdge(4, 5);
    ProvinceRoad.addEdge(5, 6);
    ProvinceRoad.addEdge(4, 6);
    ProvinceRoad.bfs(1, visitedProvince);
    for(auto it = visitedProvince.begin(); it != visitedProvince.end(); ++it){
        cout<<arr[(int)*it - 1]<<" ";
    }
    return 0;
}