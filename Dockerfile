FROM ubuntu:22.04

RUN apt update && apt install -y \
    build-essential \
    mpich

WORKDIR /app

COPY wildfire.c .

RUN mpicc wildfire.c -o wildfire

CMD ["mpirun","-np","4","./wildfire"]
