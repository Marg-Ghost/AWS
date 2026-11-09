#external
from fastapi import FASTAPI
import uvicorn
from fastapi import Basemodel

#internal
aws_ai.ai_connect

app = FASTAPI()
app.mount("/static", static("web"))

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
    uvicorn(,"127.0.0.1:8000",app)
