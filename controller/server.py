#external
#Server
import html

from fastapi import FastAPI, HTTPException
from fastapi.responses import FileResponse
from fastapi.staticfiles import StaticFiles
import uvicorn
#System
import pathlib


ROOT = pathlib.Path(__file__).resolve().parent.parent
WEBDIR = ROOT / "web"

app = FastAPI()

app.mount("/web", StaticFiles(directory=str(WEBDIR), html=True), name="web")

#########################################################
#Frontend
#########################################################
# pages
app.get("/")
async def main_monitor():
    file_name = "index.html" 
    direction = WEBDIR / file_name
    if not direction.exists():
        return HTTPException(status_code=404, detail=f"File {file_name} not found")
    return FileResponse(str(direction))

# Intel-getter
app.get("/all_servers")
async def get_all_servers():
    from ...data.get_data import Database
    db = Database("Docker.db", "docker_deamons")
    servers = db.get_all_servers()
    return {"servers": servers}

##########################################################
#Backend
##########################################################

#cpp Befahlsaufrufe
app.get("/server_status/basic/check_all")
async def check_all_server():
    from check_client import check_all_server

app.get("/server_status/settings/refresh_total_server")
async def check_all_server():
    from check_client import check_all_server_complete


if __name__ == "__main__":
    print (WEBDIR / "index.html" )
    uvicorn.run(app,host="127.0.0.1",port=9000)
