#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::vector;

double get_optimal_value(double  capacity, vector<double> weights, vector<double> values)
{
	long double value = 0;
	while (capacity != 0)
	{
		double max = 0;
		double max_add = 0;
	    double max_value = 0;
		double  max_weight = 0;
		if (weights.size() == 0 && values.size() == 0)
		{
			return value;
		}
		else 
		{
			for (int i = 0; i < values.size(); i++)
			{
				double ratio = values[i] / weights[i];
				if (max < ratio)
				{
					max = (values[i] / weights[i]);
					max_add = i;
				}
			}
			max_value = values[max_add];
			max_weight = weights[max_add];
			while (capacity != 0)
			{
				if (capacity > max_weight)
				{
					value = value + max_value;
					values.erase(values.begin() + max_add);
					capacity = capacity - max_weight;
					weights.erase(weights.begin() + max_add);
					break;
				}
				else
				{
					double value_this = (max_value / max_weight) *capacity;
					value = value + value_this ;
					capacity = 0;
					break;
				}
			}
		}
	}
	return value;
}

int main() {
	int n;
	double  capacity;
	std::cin >> n >> capacity;
	vector<double> values(n);
	vector<double> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}