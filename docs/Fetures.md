# Project Planned Fetures
## Vision
Main purpuse MDS-Tool:
 -> AI powerd system to make serverapplication (via docker) hosting easy
 -> Reads logs and Informes you what is broken and how bad It is 
 -> Find solutions to the Problems and beeing able to fix it form the web app (no need to interact with the server extra)
 -> let changes be Commited and cloed direktzly to Github

Specialty:
 -> minimize API Reqeusts/Cost:
    - only when needed (frist : hard coded solutions)
    - limit the request to the essentials

## Func-Roadmap 
- A Web-app that ennumerates all Docker Container on the server

- Read out all logs appropriatly and transport it via a cpp src.

- Connect existing logic in cpp with the arcetecture

- Connect teh thing to a RAG PIpline with an API or ollama

- Filter hardcoded via DB

- Update Github repos or push

- Let the user see teh imposed solutions and fix it via browser easily 

- Learing : explain AI feture direktly to an AI + another RAG with sepcilizes Vector DB

- Restrictet acces to only certain areas to manage diffrent grades of ops