import sqlite3

def init_table_database_deamon() -> None:
        conn = sqlite3.connect("data/Docker.db")
        cursor = conn.cursor()
        cursor.execute(f"""
            CREATE TABLE IF NOT EXISTS database_deamon (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL,
                status TEXT NOT NULL,
                importance INTEGER NOT NULL,
                type TEXT NOT NULL,
                last_updated TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                version TEXT
            )
    """)    

if __name__ == "__main__":
    init_table_database_deamon()