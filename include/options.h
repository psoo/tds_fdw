
#ifndef OPTIONS_H
#define OPTIONS_H

#include "postgres.h"

/* valid options follow this format */

typedef struct TdsFdwOption
{
	const char *optname;
	Oid optcontext;
} TdsFdwOption;

/* option values will be put here */

typedef struct TdsFdwOptionSet
{
	char *servername;
	char *language;
	char *character_set;
	int port;
	char *database;
	int dbuse;
	char* tds_version;
	char* msg_handler;
	char *username;
	char *password;
	char *query;
	char *schema_name;
	char *table_name;
	char* row_estimate_method;
	bool sqlserver_ansi_mode;
	int match_column_names;
	int use_remote_estimate;
	int fdw_startup_cost;
	int fdw_tuple_cost;
	int local_tuple_estimate;
} TdsFdwOptionSet;

void tdsValidateOptions(List *options_list, Oid context, TdsFdwOptionSet* option_set);
void tdsGetForeignServerOptionsFromCatalog(Oid foreignserverid, TdsFdwOptionSet* option_set);
void tdsGetForeignTableOptionsFromCatalog(Oid foreigntableid, TdsFdwOptionSet* option_set);
void tdsValidateOptionSet(TdsFdwOptionSet* option_set);

#endif
