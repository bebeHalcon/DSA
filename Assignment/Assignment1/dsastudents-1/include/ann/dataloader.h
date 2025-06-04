/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   dataloader.h
 * Author: ltsach
 *
 * Created on September 2, 2024, 4:01 PM
 */

#ifndef DATALOADER_H
#define DATALOADER_H
#include "ann/xtensor_lib.h"
#include "ann/dataset.h"

using namespace std;

template<typename DType, typename LType>
class DataLoader{
public:
    class Iterator;

private:
    Dataset<DType, LType>* ptr_dataset;
    int batch_size;
    bool shuffle;
    bool drop_last;

    /*TODO: add more member variables to support the iteration*/
    unsigned long nbatch;
    int m_seed;
    xt::xarray<unsigned long> indices;

public:
    DataLoader(Dataset<DType, LType>* ptr_dataset,
            int batch_size,
            bool shuffle=true,
            bool drop_last=false,
            int seed = -1){

        /*TODO: Add your code to do the initialization */
        this->ptr_dataset = ptr_dataset;
        this->batch_size = batch_size;
        this->shuffle = shuffle;
        this->drop_last = drop_last;
        this->m_seed = seed;

        this->nbatch = ptr_dataset->len() / batch_size;
        this->indices = xt::arange<unsigned long>(0, ptr_dataset->len());

        if (this->shuffle){
            if (this->m_seed >= 0){
                xt::random::seed(this->m_seed);
            }
            xt::random::shuffle(this->indices);
        }
    }

    int get_sample_count(){ return ptr_dataset->len(); }

    virtual ~DataLoader(){}
    
    /////////////////////////////////////////////////////////////////////////
    // The section for supporting the iteration and for-each to DataLoader //
    /// START: Section                                                     //
    /////////////////////////////////////////////////////////////////////////
    
    /*TODO: Add your code here to support iteration on batch*/
    Iterator begin(){
        return Iterator(this, 0);
    }

    Iterator end(){
        return Iterator(this, nbatch);
    }

class Iterator
{
private:
    DataLoader<DType, LType> *loader;
    unsigned long index;

public:
    Iterator(DataLoader<DType, LType> *loader, unsigned long index)
    {
        this->loader = loader;
        this->index = index;
    }

    bool operator!=(const Iterator &other) const
    {
        return this->index != other.index;
    }

    Batch<DType, LType> operator*()
    {
        int start = this->index * loader->batch_size;
        int end = min(start + loader->batch_size, this->loader->get_sample_count());
        if (end + loader->batch_size > this->loader->get_sample_count()) {
            //Xử lí batch cuối
            if (!loader->drop_last) {
                end = this->loader->get_sample_count();
            }
        }

        xt::svector<unsigned long> batch_data_shape = loader->ptr_dataset->get_data_shape();
        xt::svector<unsigned long> batch_label_shape = loader->ptr_dataset->get_label_shape();
        batch_data_shape[0] = end - start;
        batch_label_shape[0] = end - start;
        xt::xarray<DType> batch_data = xt::empty<DType>(batch_data_shape);
        xt::xarray<LType> batch_label = xt::empty<LType>(batch_label_shape);

        for (int i = start; i < end; i++){
            DataLabel<DType,LType> data = loader->ptr_dataset->getitem(loader->indices[i]);
            xt::view(batch_data, i - start) = data.getData();
            if (batch_label_shape.size() > 0){
                xt::view(batch_label, i - start) = data.getLabel();
            }
        }

        if (batch_label_shape.size() > 0)
            return Batch<DType, LType>(batch_data, batch_label);
        else
            return Batch<DType, LType>(batch_data, xt::xarray<LType>());
    }

    // Prefix
    Iterator &operator++()
    {
        ++index;
        return *this;
    }

    // Postfix
    Iterator operator++(int)
    {
        Iterator it = *this;
        index++;
        return it;
    }
};
    
    /////////////////////////////////////////////////////////////////////////
    // The section for supporting the iteration and for-each to DataLoader //
    /// END: Section                                                       //
    /////////////////////////////////////////////////////////////////////////
};


#endif /* DATALOADER_H */

