#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string getHostname() {
    string hostnameFile = "/etc/hostname";
    ifstream file(hostnameFile);
    if (file) {
        std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return fileContent;
    }
    else {
        return "Error: Hostname-Not-Found";
    }
}

string getUsername() {
    return getenv("USER");
}

void printUserAndHostname(string user, string hostname) {
    cout << user << "@" << hostname << endl;
}

string getDistro()
{
    string osReleaseFile = "/etc/os-release";
    ifstream file(osReleaseFile);
    string distro;
    if (file)
    {
        string line;
        while (getline(file, line))
        {
            if (line.find("PRETTY_NAME=") != string::npos)
            {
                size_t start = line.find('"') + 1;
                size_t end = line.find_last_not_of('"');
                distro = line.substr(start, end - start + 1);
            }
        }
        file.close();

        if (!distro.empty())
        {
            return distro;
        }
    }
    return "Error: Distro-Not-Found";
}

void printDistro(string distro) {
    cout << "Distro: " << distro << endl;
}

string getCpu() {
    string cpuinfoFile = "/proc/cpuinfo";
    ifstream file(cpuinfoFile);
    string cpu;
    if (file)
    {
        string line;
        while (getline(file, line))
        {
            if (line.find("model name") != string::npos)
            {
                size_t start = line.find(':') + 2;
                size_t end = line.find_last_not_of(':');
                cpu = line.substr(start, end - start + 1);
            }
        }
    }
    return cpu;
}

void printCpu(string cpu) {
    cout << "CPU: " << cpu << endl;
}

int main() {
    printUserAndHostname(getUsername(), getHostname());
    printDistro(getDistro());
    printCpu(getCpu());

    return 0;
}
