#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "fourier.hpp"

using namespace std;

int main(int argc, char** argv){
    
    if (argc != 2){
        cout << "Falta argumento, debe ejecutar como: ./actividad modo donde modo es un entero" << endl;
    }
    
    int mode = atoi(argv[1]);
    cv::String baseDir = "C:/Users/imnot/OneDrive/Escritorio/INFORMATICA/Comunicaciones/info239-lab2-opencv-lg_tv-15";
    cv::Mat input_image = cv::imread(baseDir + "/data/casa_central.jpg"); // Lee una imagen en disco
    
    if (input_image.empty()){
        cout << "La imagen no existe, verifique la ruta" << endl;
        cin.get();
        return -1;
    }
    cv::String windowName = "Casa Central";
    cv::namedWindow(windowName); // Crea una ventana
    
    cv::Mat output_image;

    switch (mode){
        case 0:
        {
            output_image = input_image;
            break;
        }
        case 1:
        {
            // Reescalado
            cv::resize(input_image, output_image, cv::Size(100,100), 0, 0);
            break;
        }
        case 2:
        {
            /* 
            Parte 2: Separe la imagen RGB en Y, Cb, Cr. 
            Luego visualice sólo Y en escala de grises. 

            Referencias: 
            Función cvtColor: https://docs.opencv.org/4.7.0/d8/d01/group__imgproc__color__conversions.html#ga397ae87e1288a81d2363b61574eb8cab
            Función split: https://docs.opencv.org/4.7.0/d2/de8/group__core__array.html#ga0547c7fed86152d7e9d0096029c8518a
            */
            cv::cvtColor(input_image, input_image, cv::COLOR_BGR2RGB);
            cv::Mat RGB[3];
            cv::split(input_image, RGB);
            output_image = RGB[0]; //RGB[0]

            break;
        }
        case 3:
        {
            /* 
            Parte 3: Binarice la imagen en Y con un umbral de 200. 
            Visualice el resultado. Luego use un umbral de 100 y 
            compare.

            Referencias:
            Función threshold: https://docs.opencv.org/4.x/d7/d1b/group__imgproc__misc.html#gae8a4a146d1ca78c626a53577199e9c57
            */
 
           cv::threshold(input_image, output_image,200,255,cv::THRESH_BINARY);
        break;
        }
        case 4:
        {
            /* 
            Parte 4: Realice un suavizado con filtro Gaussiano 
            sobre la imagen en Y. Pruebe distintos tamaños de 
            filtro, visualice los resultados y  comente.

            Referencias:
            Función GaussianBlur: https://docs.opencv.org/4.x/d4/d86/group__imgproc__filter.html#gaabe8c836e97159a9193fb0b11ac52cf1
            */

           //Size funciona SOLO con valores impares, si tiene valores 0 toma el valor que posee sigma
           cv::GaussianBlur(input_image, output_image, cv::Size(1,1), 0);
            

            break;
        }

        case 5:
        {
            /* 
            Parte 5: Considere el siguiente filtro de 3x3 conocido 
            como Laplaciano: [[0,1,0], [1,-4,1], [0,1,0]]. 
            Convolucione la imagen en Y con el filtro. Visualice 
            el resultado y comente sobre lo que observa.

            Referencias:
            Función Filter2D: https://docs.opencv.org/4.x/d4/d86/group__imgproc__filter.html#ga27c049795ce870216ddfb366086b5a04
            Constructor del objeto Mat: https://docs.opencv.org/4.x/d3/d63/classcv_1_1Mat.html#a3620c370690b5ca4d40c767be6fb4ceb
            */
            cv::Mat filtro = (cv::Mat_<float>(3,3) << 0, 1, 0,
                                                1, -4, 1,
                                                0, 1, 0);
            cv::filter2D(input_image, output_image, -1, filtro);

            break;
        }
        case 6:
        {
            /*
            Parte 6: Ver archivo `fourier.hpp` 
            */
            output_image = filter_in_fourier(input_image);
            break;
        }
        default:
        break;
    }
    cv::imshow(windowName, output_image); 
    cv::waitKey(0); // Espera hasta que presionemos cualquier tecla
    cv::destroyWindow(windowName); // Cierra la ventana
    return 0;
}

