# include <iostream>
# include <utility>
using namespace std;

# include "Token.h"
# include "Scanner.h"
# include "Parser.h"
# include "Scheme.h"
# include "Tuple.h"
# include "Relation.h"
# include "Database.h"
# include "Node.h"
# include "Graph.h"

int main() {

  // predicate names for fake rules
  // first is name for head predicate
  // second is names for body predicates
  pair<string,vector<string>> ruleNames[] = {
    { "A", { "B", "C" } },
    { "B", { "A", "D" } },
    { "B", { "B" } },
    { "E", { "F", "G" } },
    { "E", { "E", "F" } },
  };

  vector<Rule> rules;

  for (auto& rulePair : ruleNames) {
    string headName = rulePair.first;
    Rule rule = Rule(Predicate(headName));
    vector<string> bodyNames = rulePair.second;
    for (auto& bodyName : bodyNames)
      rule.add_body(Predicate(bodyName));
    rules.push_back(rule);
  }

  Graph graph = Database::make_graph(rules);
  cout << graph.toString();

}


// What about that shadowed area? That is old code. Never venture there, my son. 
// int main() {

// 	Relation studentRelation("students", Scheme( {"ID", "Name", "Major"} ));

// 	vector<string> studentValues[] = {
// 		{"'42'", "'Ann'", "'CS'"},
// 		{"'64'", "'Ned'", "'EE'"},
// 	};

// 	for (auto& value : studentValues) studentRelation.add_tuple(Tuple(value));

// 	Relation courseRelation("courses", Scheme( {"ID", "Course"} ));

// 	vector<string> courseValues[] = {
// 		{"'42'", "'CS 100'"},
// 		{"'32'", "'CS 232'"},
// 	};

// 	for (auto& value : courseValues) courseRelation.add_tuple(Tuple(value));

// 	Relation rel_new = studentRelation.join(courseRelation);

// 	cout << "joined relation:\n" << rel_new.toString() << endl << endl;

// 	vector<string> reorder = {"Course", "Name", "ID", "Major"};

// 	cout << reorder.size() << endl;

// 	cout << "reordering columns:\n" << rel_new.projector(reorder).toString() << endl;


// }


// test code for the joinable function
// int main() {

// 	Scheme scheme1( { "A", "B" } );
// 	Scheme scheme2( { "B", "C" } );

// 	Tuple tuple1( {"'1'", "'2'"} );
// 	Tuple tuple2( {"'3'", "'4'"} );

// 	Scheme scheme3( { "X", "Y" } );
// 	Scheme scheme4( { "X", "Y", "Z" } );

// 	Tuple tuple3( {"'1'", "'4'"} );
// 	Tuple tuple4( {"'1'", "'2'", "'4'"} );


// 	cout << "Testing Scheme1 : Scheme 2; tuple 1 : tuple 2" << endl;
// 	cout << Relation::joinable(scheme1, scheme2, tuple1, tuple2) << endl;

// 	cout << "Testing Scheme 2 : Scheme 3; tuple 1 : tuple 2" << endl;
// 	cout << Relation::joinable(scheme2, scheme3, tuple1, tuple2) << endl;

// 	cout << "Testing Scheme 3 : Scheme 4; tuple 1 : tuple 4" << endl;
// 	cout << Relation::joinable(scheme3, scheme4, tuple1, tuple4) << endl;

// 	cout << "Testing Scheme 3 : Scheme 4; tuple 3 : tuple 4" << endl;
// 	cout << Relation::joinable(scheme3, scheme4, tuple3, tuple4) << endl;

// }


// main function for project 4
// int main(int argc, char *argv[]){
// 	if(argc < 2){
// 		cout << "database requires at least one argument <filename>" << endl;
// 		return 1;
// 	}

// 	Database death_star(argv[1]);
// 	if(!death_star.get_success()){
// 		cout << "failed to parse file. exiting." << endl;
// 		return 1;
// 	}
// 	cout << death_star.evaluate_all();

// }


 
// int main(){
// 	vector<string> names = {"a","b","c","d","e"};
// 	Scheme scheme(names);
// 	Relation relation("student", scheme);
// 	vector<vector<string> > values = {
// 		{"2","2","4","4","4"},
// 		{"2","2","4","2","2"}
// 	};

// 	for(vector<string> value : values){
// 		Tuple tuple(value);
// 		relation.add_tuple(tuple);
// 	}

// 	cout << "relation:" << endl;
// 	cout << relation.toString() << endl;

// 	vector<int> indices = {0,1,3,4};
// 	relation = relation.select_similar(indices);
// 	cout << "selected similar" << endl;
// 	cout << relation.toString() << endl;;

// 	vector<string> re = {"z", "z", "x", "z", "z"};
// 	relation = relation.rename(names, re);
// 	cout << "renamed:" << endl;
// 	cout << relation.toString() << endl;

// 	relation = relation.projector(re);
// 	cout << "projected:" << endl;
// 	cout << relation.toString() << endl;

// }




// old code for lab 2
// int main(int argc, char *argv[]) {
//   if(argc < 2){
// 		cout << "datalog requires at least one argument <filename>" << endl;
// 		return 1;
// 	}

// 	// Scanner s = Scanner();
// 	// if(!s.readFile(argv[1])){
// 	// 	cout << "failed to read file: " << argv[1] << endl;
// 	// 	throw "file read error";
// 	// }
// 	// vector<Token> tokens = s.Scan();
// 	// for(unsigned int i = 0; i < tokens.size(); i++){
// 	// 	cout << tokens.at(i).toString() << endl;
// 	// }
// 	// cout << "Total Tokens = " << tokens.size() << endl;

//   Parser p = Parser(argv[1]);
//   if(p.true_parse()){
//     cout << "Success!" << endl;
// 	cout << p.toString();
//   }else{
//     // cout << "uh oh" << endl;
//   }
// }

// old code for lab 1
// int main(){
// 	vector<Token> tokens = {
//     Token(ID,"Ned",2),
//     //Token(LEFT_PAREN,"(",2),
//     Token(ID,"Ted",2),
//     Token(COMMA,",",2),
//     Token(ID,"Zed",2),
//     Token(RIGHT_PAREN,")",2),
//   };
	
// 	Parser p = Parser(tokens);
// 	p.scheme();
// }