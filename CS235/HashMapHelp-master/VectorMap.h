#include <iostream>
#include <vector>
using namespace std;

template <typename Name, typename Value>
class VectorMap {
  private:
	vector<Name> name_vector;
	vector<Value> value_vector;
  public:
    Value &operator [](Name param) {
    	return at(param);
    }
	Value &at(Name param) {
		// O(n)
		for(int i = 0; i < name_vector.size(); i++) {
			if(param == name_vector[i]) {
				return value_vector[i];
			}
		}
		// We didnt find it, we need to create an entry
		name_vector.push_back(param);
		Value emptyval;
		value_vector.push_back(emptyval);
		return value_vector.back();
	}
};