#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
	{
	VectorXd rmse(4);
	rmse << 0, 0, 0, 0;
	float t = estimations.size();

	// check the validity
	if (t == 0)
	{
		cout << "Error RMSE:  estimations.size() = 0" << endl;
		return rmse;
	}

	if (t != ground_truth.size())
	{
		cout << "Error RMSE: mismatch sizes of estimation & ground truth " << endl;
	return rmse;
	}

	// Squared Residuals
	for (unsigned int i = 0; i < estimations.size(); ++i)
	{
		VectorXd residual = estimations[i] - ground_truth[i];

		residual = residual.array()*residual.array();
		rmse += residual;
	}
	
	// Calculation of MEan
	rmse = rmse / estimations.size();
	rmse = rmse.array().sqrt();
	//cout << "RMSE:" << rmse << endl;
	return rmse;
}
}