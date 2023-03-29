# Tutorial de [OpenCV](https://opencv.org/about/) 

OpenCV (Open Source Computer Vision Library) es una librería enfocada en visión computacional y *machine learning* con más de 2500 algoritmos optimizados, una gran comunidad de usuarios y amplia adopción por parte de empresas.

La librería está escrita en C++ pero tiene interfaces para Python, Java y MATLAB. Adicionalmente tiene algunos algoritmos implementados en GPU. OpenCV fue diseñada pensando en aplicaciones de visión computacional que trabajan en tiempo real. 

En esta actividad haremos un tutorial de OpenCV en lenguaje C++. Puede instalar las librerías necesarias (en sistema Linux) usando el archivo de configuración para manejador de paquetes `conda` en la raiz de este repositorio: 

    conda env create -f environment.yml

Luego simplemente active el ambiente con:

    conda activate opencv

Con esto ya podría compilar el programa utilizando 

    make

Finalmente ejecutarlo con:

    ./activity 0

Las instrucciones de la actividad práctica se encuentran en los comentarios de `activity.cpp`
