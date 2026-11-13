if [ $1 -z ]; then
    echo "Missing container name"
fi
sudo docker logs $1 > logs_$1_data.txt