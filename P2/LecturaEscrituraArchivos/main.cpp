#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*class Usuario {
public:
    int id;
    string nombre;
};*/

int main() {
    string filename = "usuarios.csv";
    ofstream file(filename);
    file << "ID,NAME,OS" << endl;
    file << "0,david,windows" << endl;
    file << "1,quique,linux" << endl;
    file.close();


    ifstream r_file(filename);
    string line, column_name;
    int value = 0;
    vector<int> numbers;
    vector<string> headers;
    if (r_file.good()) {
        getline(r_file, line);
        stringstream r_line(line);
        while (getline(r_line, column_name, ',')) {
            cout << column_name << "----";
            headers.push_back(column_name);
        }
    }
    cout << endl;

    while (getline(r_file, line)) {
        stringstream r_line(line);
        int column_id = 0;
        while (r_line >> value) {
            cout << value << endl;
            numbers.push_back(value);
            if (r_line.peek() == ',') {
                r_line.ignore();
            }
            column_id++;
        }
    }
    r_file.close();
    cout << endl;

    for (auto &header: headers) {
        cout << header << "----";
    }
    cout << endl;

    for (int number: numbers) {
        cout << number << endl;
    }

    return 0;
}
