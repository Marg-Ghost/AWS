import sqlite3

class Database:
    def __init__(self,server : str, table : str):
        self.servers = server
        self.table = table

    def get_all_servers(self) -> list:
        ... # Connect to the SQLite database

    def inster_data(self) -> None:
        ... # Insert data into the SQLite database

    def update_data(self) -> None:
        ... # Update data in the SQLite database

    def delete_data(self, name: str) -> None:
        ... # Delete data from the SQLite database


    