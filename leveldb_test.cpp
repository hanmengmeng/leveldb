// leveldb_test.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <tchar.h>
#include <iostream>

#include "leveldb/db.h"
#include "leveldb/options.h"
#include "leveldb/status.h"

const char *DB_PATH = "D:\\test.db";

void WriteDb()
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, DB_PATH, &db);

    if (status.ok()) {
        status = db->Put(leveldb::WriteOptions(), "3key_3", "{'hello', 'workld3'}");
        if (status.ok()) {
            db->Put(leveldb::WriteOptions(), "4key_2", "{'hello', 'workld2'}");
        }

        delete db;
    }
}

void ReadDb()
{
    leveldb::DB* db;
    leveldb::Options options;
    leveldb::Status status = leveldb::DB::Open(options, DB_PATH, &db);

    if (status.ok()) {
        leveldb::Iterator *it = db->NewIterator(leveldb::ReadOptions());

        for (it->Seek("3"); it->Valid(); it->Next()) {
            std::cout << "key: " << it->key().ToString() << "  value: "<< it->value().ToString() << std::endl;
        }
    }
}
int _tmain(int argc, _TCHAR* argv[])
{
    ReadDb();

    system("pause");
	return 0;
}

