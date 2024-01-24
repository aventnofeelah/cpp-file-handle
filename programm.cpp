#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <limits>

using namespace std;

int main(){
    class FilesApp{
    private:
        int answer;
        string file_name;
        string text;
        string file_path;
        string file_ready;

    public: 
        void exitFunc(){
            exit(0);
        }

        void deleteFunc(){
            cout << "Enter file name to delete: " << endl;
            char file[20];
            cin >> file;
            int result = remove(file);
            cout << result;
            startFunc();

        }

        void readFunc(){
            cout << "Enter file name you want open: " << endl;
            cin >> file_name;
            string file_text;
            ifstream MyReadFile(file_name);
            while (getline(MyReadFile, file_text)) {
            cout << file_text << endl;
            }
            MyReadFile.close();
            startFunc();
        }

        void writeFunc(){
            cout << "Write file name you want to write to: " << endl;
            cin >> file_name;
            ofstream MyFile(file_name);
            cout << "Enter text and end it with ';': " << endl;
            getline(cin, text, ';');
            MyFile << text;
            MyFile.close();
            startFunc();
        }

        void createFunc(){
            cout << "Enter file path: " << endl;
            getline(cin, file_path);
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter file name: " << endl;
            cin >> file_name;
            file_ready = file_path + file_name;
            cout << file_ready;
            ofstream outfile(file_ready);
            outfile.close();
            startFunc();
        };

        void startFunc(){
            cout << "Choose what you want to do: " << endl;
            cout << "1.Create file." << endl;
            cout << "2.Write to file." << endl;
            cout << "3.Read file." << endl;
            cout << "4.Delete file." << endl;
            cout << "0.Exit." << endl;
            cin >> answer;
            switch(answer){
                case 0:
                    exitFunc();
                    break;
                case 1:
                    createFunc();
                    break;   
                case 2:
                    writeFunc();
                    break; 
                case 3:
                    readFunc();
                    break; 
                case 4:
                    deleteFunc();
                    break;
            }
        }
    };
    FilesApp object;
    object.startFunc();

    return 0;
}
