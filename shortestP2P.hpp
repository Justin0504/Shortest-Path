#include<iostream>
#include<list>
#include<vector>
#include<climits>
// You are not allowed to include additional libraries

#define INF INT_MAX

using namespace std;

class ShortestP2P {
  public:
      ShortestP2P() {}

      /* Read the graph from stdin
       * The input has the following format:
       *
       * Firstline: 1 int, the total number of vertices, X.
       * Secondline: 1 int, the total number of edges between vertices, Y.
       * A set of Y lines, each line contains tuple of 2 int and 1 int (not int!), in the format of: A(point 1, unsigned) B(point 2, unsigned) dist(distance, int)
       *
       * Example:
       * 4
       * 4
       * 0 1 5
       * 1 2 -1
       * 2 3 4
       * 3 1 6
       * 
       * 
       * 
       *
       * Vertices that are not connected have an infinitly large distance. You may use INF (previously defined at the top of this cope snippet) for infinitly large distance.
       * 
       * Special: when the graph is not proper, where there exist any pair of vertices whose minimum distance does not exist, terminate immediately by printing:
       * cout << "Invalid graph. Exiting." << endl;
       *
       * Note: vertex pairs that are not connected, which have infinitely large distances are not considered cases where "minimum distances do not exist".
       */
      void readGraph(){
        int Vertices, Edges;
        cin >> Vertices >> Edges;

        dist.resize(Vertices, vector<int>(Vertices, INF));

        for (int i = 0; i < Vertices; ++i) {
            dist[i][i] = 0; 
        }

        for (int i = 0; i < Edges; ++i) {
          int u, v;
          int weight;
          cin >> u >> v >> weight;
          dist[u][v]=weight;
        }
        
        if (!isValidGraph(Vertices)) {
            cout << "Invalid graph. Exiting." << endl;
            exit(0);
        }
        
      }

      /* Input: 2 vertices A and B
       * Output: distance between them.
       * cout << dist << endl;
       *
       * When the A and B are not connected print INF:
       * cout << "INF" << endl;
       */
      void distance(int A, int B){

        if (A == -1) {
            exit(0); 
        }

        if (dist[A][B] == INF) {
            cout << "INF" << endl; 
        } else {
            cout << dist[A][B] << endl; 
        }
      }

  private:
    // internal data and functions.
    vector<vector<int>> dist; 

    bool isValidGraph(int V) {
       // no connection, dis=INF

        for (int k = 0; k < V; k++) {

          for (int i = 0; i < V; i++) {
              for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF
                &&dist[i][k]+dist[k][j]<dist[i][j]) {
                  dist[i][j] =dist[i][k]+dist[k][j];
                }
              }
          }
          for (int i = 0; i < V; ++i) {
            if (dist[i][i] < 0) {
                return false; 
            }
          }
          
        }

        

        return true; 
    }
      

};
