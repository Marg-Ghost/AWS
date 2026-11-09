#external
from fastapi import FASTAPI
import uvicorn
from fastapi import Basemodel

#internal
BASEDIR = Path(__file__).resolve().parent()
import BASEDIR.aws_ai.ai_connect

app = FASTAPI()
app.add_middleware(
    allow_origins=["*"],
    allow_methods=["*"],
    allow_headers=["*"]
)

#########################################################
#Action-Contorler
#########################################################
post.app("/ai_endpoint")
async def eval_problem(problem : str) -> dict:
    #AI endpoint

    #connection to monitor


#########################################################
#Monitor 
#########################################################
get.app("/")
async def main_monitor():
    pass



if __name__ == "__main__":
    uvicorn.run(app,host="127.0.0.1",port=9000)
