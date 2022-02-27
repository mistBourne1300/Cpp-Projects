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

public:
    Relation(const string& name, const Scheme& scheme) : name(name), scheme(scheme) {}
    void add_tuple(const Tuple& tuple) {
        tuples.insert(tuple);
    }

    string toString() const{
        stringstream out;
        for(Tuple tuple : tuples){
            out << tuple.toString(scheme) << endl;
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
};