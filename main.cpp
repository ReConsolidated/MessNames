#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

void Zadymka(string sciezkaDoFolderu)
{
    vector<string> filenames;
    string dodajGwiazdke = sciezkaDoFolderu + "*";
    string directoryPath(dodajGwiazdke.c_str());
    string bufor = "Messed by Consolidated.txt";

    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = FindFirstFile(directoryPath.c_str(), &FindFileData);

    if (hFind  != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
            {
                filenames.push_back(FindFileData.cFileName);
                string oldname, newname;
                oldname = sciezkaDoFolderu + FindFileData.cFileName;
                newname = sciezkaDoFolderu + bufor;
                if (rename(oldname.c_str(), newname.c_str()) == 0)
                {
                    cout << "You messed everything up!" << endl;
                }
                else
                {
                    cout << "You messed with the wrong guy" << endl;
                    cout << newname << endl;
                    cout << oldname << endl;
                }
                bufor = FindFileData.cFileName;
            }

        }
        while (FindNextFile(hFind, &FindFileData));

        FindClose(hFind);
    }
}

int main()
{
    cout << "Write full file path, like C:\\\\Directory\\\\ " ;
    string sciezka;
    cin >> sciezka;
    Zadymka(sciezka);


}

