/*
*   Largest Triangle Area LeetCode Problem
*   @author:  Santiago Garcia Dominguez
*   @date:    27/09/2025
*   @description: Given an array of points on the X-Y plane points where points[i] = [xi, yi]
*   return the area of the largest triangle that can be formed by any three different points
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
double largestTriangleArea(vector<vector<int>>& points);
int main(){
    vector<vector<int>> points = {{-3,0},{0,4},{3,0}};;

    cout << "Largest Triangle Area: " << largestTriangleArea(points) << endl;
    return 0;
}

double largestTriangleArea(vector<vector<int>>& points){
    float largestArea = 0.0;
    for(int i=0;i<points.size();i++){
        for(int j=i+1;j<points.size();j++){
            for(int k=j+1;k<points.size();k++){
                float currentArea= 0.5 * abs(
                        points[i][0] * (points[j][1] - points[k][1]) +
                        points[j][0] * (points[k][1] - points[i][1]) +
                        points[k][0] * (points[i][1] - points[j][1])
                );

                (currentArea > largestArea) ? largestArea = currentArea : largestArea;
                
            }
        }
    }

    return largestArea;
}