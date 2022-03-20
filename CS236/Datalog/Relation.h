# pragma once
# include <vector>
# include <string>
# include <sstream>
# include <set>
using namespace std;

# include "Tuple.h"
# include "Scheme.h"

class Relation {
private:
    string name;
    Scheme scheme;
    set<Tuple> tuples;

    bool contains(vector<int> vect, int item){
        for(int i: vect){
            if(i==item){
                return true;
            }
        }
        return false;
    }

    bool contains(vector<string> vect, string item){
        for(string s: vect){
            if(s==item){
                return true;
            }
        }
        return false;
    }

    vector<string> get_unique(vector<string> vect){
        vector<string> unique;
        for(string s : vect){
            if(!contains(unique,s)){
                unique.push_back(s);
            }
        }
        return unique;
    }

    Tuple join_tuples(const Scheme& left_scheme, const Scheme& right_scheme, const Tuple& left_tuple, const Tuple& right_tuple){
        // create a new tuple vector and initialize it with a copy of the left tuple (to match the way the Schemes are made)
        vector<string> new_tuple_vect = left_tuple;
        
        // for each item in the right tuple, if the left scheme does not contain the
        // corresponding right scheme's parameter, add the item to the new tuple
        for(unsigned int i = 0; i<right_tuple.size(); i++){
            if(!contains(left_scheme, right_scheme.at(i))){
                new_tuple_vect.push_back(right_tuple.at(i));
            }
        }
        return Tuple(new_tuple_vect);
    }

public:
    Relation(const string& name, const Scheme& scheme) : name(name), scheme(scheme) {}

    static bool joinable(const Scheme& left_scheme, const Scheme& right_scheme, const Tuple& left_tuple, const Tuple& right_tuple){
        for (unsigned left_index = 0; left_index < left_scheme.size(); left_index++) {
            const string& left_name = left_scheme.at(left_index);
            const string& left_value = left_tuple.at(left_index);
            for (unsigned right_index = 0; right_index < right_scheme.size(); right_index++) {
                const string& right_name = right_scheme.at(right_index);
                const string& right_value = right_tuple.at(right_index);
                if(left_name == right_name && left_value != right_value){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool add_tuple(const Tuple& tuple) {
        return tuples.insert(tuple).second;
    }

    string toString() const{
        stringstream out;
        for(Tuple tuple : tuples){
            out << "  " << tuple.toString(scheme) << endl;
        }
        return out.str();
    }

    Relation select(int index, const string& value) const{
        Relation result(name, scheme);
        for(Tuple tuple : tuples){
            if(tuple.at(index) == value){
                result.add_tuple(tuple);
            }
        }
        return result;
    }

    Relation select_similar(vector<int> indices){
        Relation result(name, scheme);
        for(Tuple tuple : tuples){
            bool included = true;
            string compare = tuple.at(indices.at(0));
            for(int i : indices){
                if(tuple.at(i) != compare){
                    included = false;
                    break;
                }
            }
            if(included){
                result.add_tuple(tuple);
            }
        }
        return result;
    }

    Relation projection(vector<string>& cols, vector<int> ignore = {}){
        cols = get_unique(cols);
        vector<unsigned int> indices;
        for(string col : cols){
            for(unsigned int i = 0; i < scheme.size(); i++){
                if(contains(ignore,i)){
                    continue;
                }
                if(scheme.at(i) == col){
                    indices.push_back(i);
                    break;
                }
            }
        }

        Relation result(name, cols);
        for(Tuple tuple : tuples){
            vector<string> values;
            for(unsigned int i : indices){
                values.push_back(tuple.at(i));
            }
            result.add_tuple(Tuple(values));
        }

        return result;

    }

    Relation rename(vector<string> old, vector<string> re){
        if(old.size() != re.size()){
            cout << "rename() function requires old and re to be the same size" << endl;
            throw "rename() function requires old and re to be the same size";
        }

        Scheme relabeled = scheme;
        for(unsigned int i = 0; i < old.size(); i++){
            for(unsigned int j = i; j < relabeled.size(); j++){
                if(old.at(i) == relabeled.at(j)){
                    relabeled[j] = re.at(i);
                }
            }
        }

        Relation result(name, relabeled);
        for(Tuple tuple : tuples){
            result.add_tuple(tuple);
        }
        return result;
    }

    Relation join(const Relation& r){
        const Scheme& left_scheme = scheme;
        const Scheme& right_scheme = r.get_scheme();


        // create a new scheme from the left scheme, then push back the unique right_scheme strings
        vector<string> new_scheme_vect = left_scheme;
        for(string s : right_scheme){
            if(!contains(new_scheme_vect,s)){
                new_scheme_vect.push_back(s);
            }
        }

        Relation joined(name, Scheme(new_scheme_vect));

        // for each tuple, add it to the relation, if they are joinable
        for(const Tuple& left_tuple : tuples){
            for(const Tuple& right_tuple : r.get_tuples()){
                if(joinable(left_scheme, right_scheme, left_tuple, right_tuple)){
                    joined.add_tuple(join_tuples(left_scheme, right_scheme, left_tuple, right_tuple));
                }
            }
        }
        
        return joined;
    }
    
    set<Tuple> get_tuples() const {return tuples;}
    string get_name() const {return name;}
    Scheme get_scheme() const {return scheme;}
    int size() {return tuples.size();}
};