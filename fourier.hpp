#include <opencv2/opencv.hpp>

/*
Parte 6: Filtrado en dominio de frecuencia

La siguiente rutina calcula la transformada de fourier 
de la imagen de entrada y la separa en los espectros 
de magnitud y fase. Primero estudie el código, lea la 
documentación y discuta con sus compañeros que hace cada
linea de la rutina. Luego implemente una máscara 
multiplicativa para el espectro de magnitud (mag) en donde 
se indica. Implemente una máscara que deje pasar sólo las 
frecuencias más bajas.
 */

cv::Mat filter_in_fourier(cv::Mat input_image){
    cv::Mat gray, fourier_complex, fourier_real[2], mag, angle, output_image;
    cv::cvtColor(input_image, gray, cv::COLOR_BGR2GRAY);
    gray.convertTo(gray, CV_32F);
    cv::dft(gray, fourier_complex, cv::DFT_SCALE | cv::DFT_COMPLEX_OUTPUT);
    cv::split(fourier_complex, fourier_real);
    cv::cartToPolar(fourier_real[0], fourier_real[1], mag, angle);
    // Filtre el espectro de magnitud aquí:
    cv::polarToCart(mag, angle, fourier_real[0], fourier_real[1]);
    cv::merge(fourier_real, 2, fourier_complex);
    cv::dft(fourier_complex, gray, cv::DFT_INVERSE | cv::DFT_REAL_OUTPUT);
    gray.convertTo(output_image, CV_8U);
    return output_image;
}


