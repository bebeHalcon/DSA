/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tanh.cpp
 * Author: ltsach
 * 
 * Created on September 1, 2024, 7:03 PM
 */

#include "layer/Tanh.h"
#include "sformat/fmt_lib.h"
#include "ann/functions.h"

Tanh::Tanh(string name) {
    if(trim(name).size() != 0) m_sName = name;
    else m_sName = "Tanh_" + to_string(++m_unLayer_idx);
}

Tanh::Tanh(const Tanh& orig) {
    m_sName = "Tanh_" + to_string(++m_unLayer_idx);
}

Tanh::~Tanh() {
}

xt::xarray<double> Tanh::forward(xt::xarray<double> X) {
    //YOUR CODE IS HERE
    // Tính e^X và e^(-X)
    xt::xarray<double> exp_X = xt::exp(X);          // e^X
    xt::xarray<double> exp_neg_X = xt::exp(-X);     // e^(-X)
    
    // Tính tanh(X) = (e^X - e^(-X)) / (e^X + e^(-X))
    m_aCached_Y = (exp_X - exp_neg_X) / (exp_X + exp_neg_X);
    
    return m_aCached_Y;
}
xt::xarray<double> Tanh::backward(xt::xarray<double> DY) {
    //YOUR CODE IS HERE
    // Tính gradient theo công thức DX = DY ⊙ (1 - Y ⊙ Y)    
    xt::xarray<double> DX = DY * (1.0 - m_aCached_Y * m_aCached_Y);
    
    return DX;
}

string Tanh::get_desc(){
    string desc = fmt::format("{:<10s}, {:<15s}:",
                    "Tanh", this->getname());
    return desc;
}
