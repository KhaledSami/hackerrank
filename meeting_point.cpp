#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

/* O(N * LogN)
The distance(D) between 2 points is the [diagonal steps + direct steps]
Assume that diffX = abs(X-X1)
Assume that diffY = abs(Y-Y1)
Then D = min(diffX,diffY) + max(diffX-diffY) - min(diffX,diffY) Which is ==> max(diffX-diffY)
Given the fact of getting the max absolute between two numbers X,Y ==> max(abs(X), abs(Y)) = (abs(X-Y) + abs(X+Y))/2
Since D = max(diffX-diffY), then D = max(abs(x-x1), abs(y-y1)) = (abs(x+y-(x1+y1) ) + abs(x-y-(x1-y1)))/2
Then D = abs(x+y-(x1+y1)) / 2 + abs(x-y-(x1-y1))/2
Then D = abs( ((x+y)/2) - ((x1 + y1)/2)  )     +    abs( ((x-y)/2) - ((x1-y1)/2) )
Then if we transform each point (x,y) to be (u,v) such that  u = (x+y)/2, v = (x-y)/2 then we can get D easily by
D = abs(u0 - u1) + abs(v0 - v1) which is known as Manhattan distance
So the new problem will be given set of points, return the min Manhattan distance if the meeitng will be at one of these points
*/
void calculateManhattan(vector<pair<double, int>>& points, vector<double>& distance) {
    double dist = 0;
    for (int i = 1; i < points.size(); i++) {
        dist+= std::abs(points[i].first - points[0].first);
    }
    distance[points[0].second] += dist;
    for (int i = 1; i < points.size(); i++) {
        double cur_distance = dist - max(0.0, (double)((double)points.size() - i - 1) * 
                                             std::abs(points[i].first - points[i - 1].first));
        cur_distance+= max(0.0, (double)(i - 1) * std::abs(points[i].first - points[i - 1].first));
        distance[points[i].second] += cur_distance;
        dist = cur_distance;                                         
    }
}
long long int meetingPoint(vector<long long> x, vector <long long> y) {
    if (x.empty()) {
        return 0;
    }
    vector<pair<double, int> > point_x_idx(x.size());
    vector<pair<double, int> > point_y_idx(y.size());
    for (int i = 0; i < x.size(); i++) {
        point_x_idx[i] = make_pair((double)(x[i] + y[i]) / 2.0 , i);
        point_y_idx[i] = make_pair((double)(x[i] - y[i]) / 2.0 , i);
    }
    sort(point_x_idx.begin(), point_x_idx.end());
    sort(point_y_idx.begin(), point_y_idx.end());
    
    // value at index i represents the sum of distances from the other houses to point number i 
    vector<double> point_to_distance(x.size(), 0);
    
    calculateManhattan(point_x_idx, point_to_distance);
    calculateManhattan(point_y_idx, point_to_distance);
    sort(point_to_distance.begin(), point_to_distance.end());
    return point_to_distance[0];
}
/* Tail starts here */
int main() {
    long long int res;
   
    int _a_size,_a_i;
    scanf("%d", &_a_size);
    vector < long long int > _x;
    vector < long long int > _y;
    long long int _x_item,_y_item;
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        scanf("%lld %lld", &_x_item,&_y_item);
        _x.push_back(_x_item);
        _y.push_back(_y_item);
    }
    res = meetingPoint(_x,_y);
    printf("%lld\n",res);    
    return 0;
}
