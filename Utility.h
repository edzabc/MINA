#ifndef __FILEHANDLER__
#define __FILEHANDLER__
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

template <typename T>
vector< vector<T> > read(  const char *filename ) {
	ifstream inp(filename);
	string line;	

	vector< vector<T> > ret;
	int i = 0;
	while( getline(inp,line) ) {
		istringstream sin(line);

		string genename;
		vector<T> row;
		T value;
		sin >> genename;
		while( sin >> value ) {
			row.push_back(value);
		}

		ret.push_back(row);
	}
	inp.close();	
	return ret;
}

vector< string > readSymbols( const char *filename ) {
	vector< string > ret;
	ifstream inp(filename);
	string tok;
	while( inp >> tok ) {
		ret.push_back(tok);
	}
	return ret;
}

template <typename T>
double getMedian( vector<T> seq ) {
	sort( seq.begin(), seq.end() );
	const size_t size = seq.size();
	if( size % 2 == 1 ) {
		return seq[size/2];
	}
	else {
		return 0.5 * ( seq[size/2-1] + seq[size/2] );
	}
}


vector<string> tokenization( const string &s ) {
    istringstream sin( s );
    vector<string> ret;
    string tok;
    while( sin >> tok ) ret.push_back( tok );
    return ret;
}

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
// source : http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void errorMsg( const string &msg ) {
    cerr << "Error: " << msg << endl;
    exit(1);
}

string join( const vector<string> &vec, const string &delim ) {
    string ret;

    ret += vec.front();

    for( size_t i = 1 ; i < vec.size() ; ++i ) {
        ret += delim;
        ret += vec[i];
    }
    
    return ret;
}

#endif
