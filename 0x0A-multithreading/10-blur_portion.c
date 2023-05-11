#include "multithreading.h"

/**
 * sum_conv -create a convolutional pixel
 * @portion: portion struct with the portion of the image
 * @i: value x for the initial point
 * @j: value y for the initial point
 * @img: matrix of pixel representing the original image
 * Return: pixel struct with the news rbg values
 */
pixel_t *sum_conv(blur_portion_t const *portion, size_t i, size_t j,
		pixel_t ***img)
{
	pixel_t *new_pixel = NULL;
	float conv_s = 0.0, **kernel = NULL;
	float pixel_r = 0.0, pixel_b = 0.0, pixel_g = 0.0;
	ssize_t size_kernel = 0, mid_kernel = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	new_pixel = calloc(1, sizeof(pixel_t));
	size_kernel = portion->kernel->size;
	mid_kernel = size_kernel / 2;
	kernel = portion->kernel->matrix;

	y1 = i - mid_kernel;
	x1 = j - mid_kernel;
	y2 = i + mid_kernel;
	x2 = j + mid_kernel;
	while (y1 <= y2)
	{
		x1 = j - mid_kernel;
		while (x1 <= x2)
		{
			if (y1 > -1 && x1 > -1 && x1 < (ssize_t)portion->img->w &&
					y1 < (ssize_t)portion->img->h)
			{
				pixel_r += (img[y1][x1]->r *
						kernel[y1 - i + mid_kernel][x1 - j + mid_kernel]);
				pixel_b += (img[y1][x1]->b *
						kernel[y1 - i + mid_kernel][x1 - j + mid_kernel]);
				pixel_g += (img[y1][x1]->g *
						kernel[y1 - i + mid_kernel][x1 - j + mid_kernel]);
				conv_s += kernel[y1 - i + mid_kernel][x1 - j + mid_kernel];
			}
			x1++;
		}
		y1++;
	}

	new_pixel->r = pixel_r / conv_s;
	new_pixel->b = pixel_b / conv_s;
	new_pixel->g = pixel_g / conv_s;

	return (new_pixel);
}
/**
 * free_all_img - free util matrix img and img_c
 * @portion: portion struct with the information of the portion
 * @img_c: matrix representation of the blur image
 * @img: matrix representation of the original image
 * Return: Nothing
 */
void free_all_img(blur_portion_t const *portion, pixel_t ***img_c,
		pixel_t ***img)
{
	size_t i = 0;

	i = 0;
	while (i < portion->img->h)
	{
		free(img_c[i]);
		free(img[i]);
		i++;
	}
	free(img_c);
	free(img);
}
/**
 * blur_portion - blur a portion of an image
 * @portion: portion struct with the information of the portion
 * Return: Nothing
 */
void blur_portion(blur_portion_t const *portion)
{
	pixel_t ***originImg = NULL, ***Img = NULL, *conv_Pixels = NULL;
	size_t i = 0, j = 0;

	originImg = calloc(portion->img->h, sizeof(img_t **));
	Img = calloc(portion->img->h, sizeof(img_t **));
	while (i < portion->img->h)
	{
		originImg[i] = calloc(portion->img->w, sizeof(img_t *));
		Img[i] = calloc(portion->img->w, sizeof(img_t *));
		i++;
	}

	i = 0;
	while (i < portion->img->h)
	{
		j = 0;
		while (j < portion->img->w)
		{
			originImg[i][j] = &(portion->img_blur->pixels[(portion->img->w * i) + j]);
			Img[i][j] = &(portion->img_blur->pixels[(portion->img->w * i) + j]);
			j++;
		}
		i++;
	}
	i = portion->y;
	while (i < portion->y + portion->h)
	{
		j = portion->x;
		while (j < portion->x + portion->w)
		{
			conv_Pixels = sum_conv(portion, i, j, originImg);
			(Img[i][j]->r) = conv_Pixels->r;
			(Img[i][j]->g) = conv_Pixels->g;
			(Img[i][j]->b) = conv_Pixels->b;
			free(conv_Pixels);
			j++;
		}
		i++;
	}
	free_all_img(portion, Img, originImg);
}
