#include <vector> 
#include <algorithm>    // std::min
using namespace std;

class Triangle109 {
public:
	vector<vector<int>> input() {
		vector<vector<int>> triangle_input;
		triangle_input.push_back(vector<int>{2});
		triangle_input.push_back(vector<int>{3, 4});
		triangle_input.push_back(vector<int>{6, 5, 7});
		triangle_input.push_back(vector<int>{4, 1, 8, 3});

		cout << "row is " << triangle_input.size() << ", col is " << triangle_input[triangle_input.size() - 1].size() << endl;
		cout << "The contents are:" << endl;
		for (int i = 0; i < triangle_input.size(); i++) {
			for (int j = 0; j < triangle_input[i].size(); j++) {
				cout << triangle_input[i].at(j) << ' ';
			}
			cout << '\n';
		}
		return triangle_input;
	}
	
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.size() == 0) {
			return 0;
		}

		vector<int> f(triangle[triangle.size() - 1].size());
		f[0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); i++) {
			for (int j = triangle[i].size() - 1; j >= 0; j--) {
				if (j == 0) {
					f[j] = f[j] + triangle[i][j];
				}
				else if (j == triangle[i].size() - 1){
					f[j] = f[j - 1] + triangle[i][j];
				}
				else {
					f[j] = min(f[j - 1], f[j]) + triangle[i][j];
				}
			}
		}


		int ret = INT_MAX;
		for (int i = 0; i < f.size(); i++) {
			ret = min(ret, f[i]);
		}
		return ret;
	}
};