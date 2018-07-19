#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

   int n = 0;
   int desk[99][99];
   vector <pair <int, int>> dd = { {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
   {2, 1}, {2, -1}, {-2, 1}, {-2, -1} };
   
   
   int count(int i, int j) {
         int c = 0;
         
         if (i >= 0 && j >= 0 && i < n && j < n && desk[i][j] == 0) {
               for (int l = 0; l < 8; l++) {
                     if (i + dd[l].first >= 0 && i + dd[l].first < n && 
                     j + dd[l].second >= 0 && j + dd[l].second < n && 
                     desk[i + dd[l].first] == 0 && desk[j + dd[l].second] == 0) {
                           c++;
                     }
               }
               return c;
         } 
      return -1;

   }

   void solve(int i, int j, int c = 2) {
       if (desk[i][j] == n * n) {
            for (int i = 0; i < n; i++) {
                   for (int j = 0; j < n; j++) {
                         cout << desk[i][j] << " ";
                   }
                   cout << "\n";
             }
           exit(0);
       }
          vector <pair <int, int>> z;

       for (int k = 0; k < 8; k++) {
             int ii = i + dd[k].first;
             int jj = j + dd[k].second;
             
             z.push_back({count(ii, jj), k});
       }
       
       sort(z.begin(), z.end());
       
       for (int l = 0; l < z.size(); l++) {
             if (z[l].first >= 0) {
                   int ii = i + dd[z[l].second].first;
                   int jj = j + dd[z[l].second].second;
                   desk[ii][jj] = c;
                   solve(ii, jj, c + 1);
                   desk[ii][jj] = 0;
             }
       }
       
   }

   int main() {
       cin >> n;
       
       for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                  desk[i][j] = 0;
            }
       }
       desk[0][0] = 1;
       solve(0, 0);
       
       cout << -1;

        return 0;
    }