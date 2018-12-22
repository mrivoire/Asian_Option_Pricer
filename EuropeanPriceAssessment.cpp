#include "EuropeanPriceAssessment.h"

EuropeanPriceAssessment::EuropeanPriceAssessment()
{
}

double EuropeanPriceAssessment::Computed1()
{
	double d1 = (log(option -> S / option -> K) + (option -> r + 0.5*pow(option -> sigma, 2)*(option -> T))) / (option -> sigma*sqrt(option -> T));
	return(d1);
}

double EuropeanPriceAssessment::Computed2()
{
	double d1 = Computed1();
	double d2 = d1 - option -> sigma * sqrt(option -> T);
	return(d2);
}

double EuropeanPriceAssessment::EstimateNd_MonteCarlo(double d, int n)
{
	int nb_points_lower_d = 0;
	double estimate_Nd = 0;
	for (int i = 0; i < n; i++)
	{
		double s = 0;
		double x;
		double y;
		do
		{
			x = 1 - 2 * (rand() / (double)RAND_MAX);
			y = 1 - 2 * (rand() / (double)RAND_MAX);
			s = x * x + y * y;
		} while (s < 0 || s > 1);

		double z = x * sqrt(-2 * log(s) / s);
		if (z < d)
		{
			nb_points_lower_d++;
		}
	}
	estimate_Nd = ((double)nb_points_lower_d / n);
	return(estimate_Nd);
}

double EuropeanPriceAssessment::EstimateNd_RiemannLeft(double d, int n)
{
	double step = (0 - d) / n;
	double rectangleArea = 0;
	double LeftRiemannSum = 0;
	double EstimateNd = 0;
	for (int i = 0; i < n; i++)
	{
		rectangleArea = step * (1 / sqrt(2 * 3.14))*exp(-pow((d + i * step) - 0, 2) / (2 * pow(option -> sigma, 2)));
		LeftRiemannSum = LeftRiemannSum + rectangleArea;
	}
	EstimateNd = 0.5 - LeftRiemannSum;
	//cout << EstimateNd << " pour d valant " << d << endl;
	return(EstimateNd);
}

double EuropeanPriceAssessment::EstimateNd_RiemannRight(double d, int n)
{
	double step = (0 - d) / n;
	double rectangleArea = 0;
	double RightRiemannSum = 0;
	double EstimateNd = 0;
	for (int i = 0; i < n; i++)
	{
		rectangleArea = step * (1 / sqrt(2 * 3.14))*exp(-pow((d + (i + 1) * step) - 0, 2) / (2 * pow(option->sigma, 2)));
		RightRiemannSum = RightRiemannSum + rectangleArea;
	}
	EstimateNd = 0.5 - RightRiemannSum;
	return(EstimateNd);
}

// Calculation of the Option Prices from the parameters estimated
double EuropeanPriceAssessment::ComputePriceOption(int n, string methodChoice)
{
	double d1 = Computed1();
	double d2 = Computed2();
	double price;
	if (methodChoice == "Monte-Carlo")
	{
		if (option->type == typeOption::call)
		{
			price = (option->S * EstimateNd_MonteCarlo(d1, n) - option->K * exp(-option->r * option->T)*EstimateNd_MonteCarlo(d2, n));
			//cout << "call :" << price << endl;
		}
		else
		{
			price = (option->K * exp(-option->r * option->T)*EstimateNd_MonteCarlo(-d2, n) - option->S * EstimateNd_MonteCarlo(-d1, n));
			//cout << "put :" << price << endl;
		}
	}
	if (methodChoice == "Left Sum Riemann")
	{
		if (option->type == typeOption::call)
		{
			price = (option->S * EstimateNd_RiemannLeft(d1, n) - option->K * exp(-option->r * option->T)*EstimateNd_RiemannLeft(d2, n));
			//cout << "call :" << price << endl;
		}
		else
		{
			price = (option->K * exp(-option->r * option->T)*EstimateNd_RiemannLeft(-d2, n) - option->S * EstimateNd_RiemannLeft(-d1, n));
			//cout << "put :" << price << endl;
		}
	}
	if (methodChoice == "Right Sum Riemann")
	{
		if (option->type == typeOption::call)
		{
			price = (option->S * EstimateNd_RiemannRight(d1, n) - option->K * exp(-option->r * option->T)*EstimateNd_RiemannRight(d2, n));
			//cout << "call :" << price << endl;
		}
		else
		{
			price = (option->K * exp(-option->r * option->T)*EstimateNd_RiemannRight(-d2, n) - option->S * EstimateNd_RiemannRight(-d1, n));
			//cout << "put :" << price << endl;
		}
	}

	return(price);
}

EuropeanPriceAssessment::~EuropeanPriceAssessment()
{
}

