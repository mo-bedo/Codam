# Inception
This project is designed to enhance knowledge in systems administration through the utilization of Docker. The task involves virtualizing multiple Docker images by creating them within a personal virtual machine.

What is Inception?
Inception stands as an individual project at Codam, demanding the establishment of an infrastructure of services using Docker, orchestrated by Docker Compose.

In the mandatory segment, a container containing nginx should be exclusively accessible through port 443, exposing the internal docker network services for public access. The nginx service connects to the wordpress container, which runs php-fpm and stores data in a mariadb service on the network. The website data for both wordpress and mariadb must be persisted, each in its respective volume.