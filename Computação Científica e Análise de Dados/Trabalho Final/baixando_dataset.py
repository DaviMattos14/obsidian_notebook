import kagglehub

# Download latest version
path = kagglehub.dataset_download("rodolfofigueroa/spotify-12m-songs")

print("Path to dataset files:", path)