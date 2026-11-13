import sqlite3

class Database:
    def __init__(self,server : str, table : str):
        self.servers = server
        self.table = table

    def get_servers(self):
        ... # Connect to the SQLite database