/*=============================================================================
# Filename: gload.cpp
# Author: Bookug Lobert
# Mail: 1181955272@qq.com
# Last Modified: 2015-10-24 19:27
# Description: firstly written by liyouhuan, modified by zengli
TODO: add -h/--help for help message
=============================================================================*/

#include "../Util/Util.h"
#include "../Database/Database.h"

using namespace std;

//[0]./gload [1]data_folder_path  [2]rdf_file_path
int
main(int argc, char * argv[])
{
	//chdir(dirname(argv[0]));
#ifdef DEBUG
	Util util;
#endif
	//system("clock");
	cout << "gload..." << endl;
	{
		cout << "argc: " << argc << "\t";
		cout << "DB_store:" << argv[1] << "\t";
		cout << "RDF_data: " << argv[2] << "\t";
		cout << "internal_data: " << argv[3] << "\t";
		cout << endl;
	}

	string _db_path = string(argv[1]);
	//if(_db_path[0] != '/' && _db_path[0] != '~')  //using relative path
	//{
	//_db_path = string("../") + _db_path;
	//}
	string _rdf = string(argv[2]);
	//if(_rdf[0] != '/' && _rdf[0] != '~')  //using relative path
	//{
	//_rdf = string("../") + _rdf;
	//}
	Database _db(_db_path);
	bool flag = _db.build(_rdf);
	if (flag)
	{
		cout << "import RDF file to database done." << endl;
	}
	else
	{
		cout << "import RDF file to database failed." << endl;
	}
	
	Database _db1(_db_path);
	_db1.load();
	string _in_file = string(argv[3]);
	_db1.loadInternalVertices(_in_file);
	
	return 0;
}

