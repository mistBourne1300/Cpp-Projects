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

    vector<string> get_unique(vector<string> vect){
        vector<string> unique;
        for(string s : vect){
            bool found = false;
            for(string v : unique){
                if(s == v){
                    found = true;
                    break;
                }
            }
            if(!found){
                unique.push_back(s);
            }
        }
        return unique;
    }

public:
    Relation(const string& name, const Scheme& scheme) : name(name), scheme(scheme) {}

    static bool joinable(const Scheme& left_scheme, const Scheme& right_scheme, const Tuple& left_tuple, const Tuple& right_tuple){
        for (unsigned left_index = 0; left_index < left_scheme.size(); left_index++) {
            const string& left_name = left_scheme.at(left_index);
            const string& left_value = left_tuple.at(left_index);
            cout << "left name: " << left_name << " value: " << left_value << endl;
            for (unsigned right_index = 0; right_index < right_scheme.size(); right_index++) {
                const string& right_name = right_scheme.at(right_index);
                const string& right_value = right_tuple.at(right_index);
                cout << "\tright name: " << right_name << " value: " << right_value << endl;
                if(left_name == right_name && left_value != right_value){
                    cout << "\t\t^^ Not joinable." << endl;
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void add_tuple(const Tuple& tuple) {
        tuples.insert(tuple);
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

    Relation projector(vector<string> cols){
        cols = get_unique(cols);
        vector<unsigned int> indices;
        for(string col : cols){
            for(unsigned int i = 0; i < scheme.size(); i++){
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
            //cout << "rename() function requires old and re to be the same size" << endl;
            throw "rename() function requires old and re to be the same size";
        }
        // cout << "inside rename()" << endl;

        Scheme relabeled = scheme;
        for(unsigned int i = 0; i < old.size(); i++){
            for(unsigned int j = i; j < relabeled.size(); j++){
                if(old.at(i) == relabeled.at(j)){
                    // cout << "  " << relabeled[j] << re.at(i) << endl;
                    relabeled[j] = re.at(i);
                }
            }
        }

        // for(unsigned int i = 0; i < relabeled.size(); i++){
        //     for(unsigned int j = i; j < old.size(); j++){
        //         if(old.at(j) == relabeled.at(i)){
        //             cout << "  " << relabeled[i] << re.at(j) << endl;
        //             relabeled[i] = re.at(j);
        //         }
        //     }
        // }
        Relation result(name, relabeled);
        for(Tuple tuple : tuples){
            result.add_tuple(tuple);
        }
        return result;
    }

    Relation join(const Relation& r){
        const Scheme& left_scheme = scheme;
        const Scheme& right_scheme = r.get_scheme();
        for(const Tuple& left_tuple : tuples){
            cout << "left tuple: " << left_tuple.toString(left_scheme) << endl;
            for(const Tuple& right_tuple : r.get_tuples()){
                cout << "\tright tuple: " << right_tuple.toString(right_scheme) << endl;
            }
        }
        
        return Relation(name, scheme);
    }
    
    set<Tuple> get_tuples() const {return tuples;}
    string get_name() const {return name;}
    Scheme get_scheme() const {return scheme;}
    int size() {return tuples.size();}
};