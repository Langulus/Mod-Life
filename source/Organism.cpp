///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "Organism.hpp"
#include "Life.hpp"


/// Organism construction                                                     
///   @param producer - the producer                                          
///   @param descriptor - instructions for configuring the organism           
Organism::Organism(Ecosystem* producer, Describe descriptor)
   : Resolvable   {this}
   , ProducedFrom {producer, descriptor} {
   VERBOSE_LIFE("Initializing...");
   Couple(descriptor);
   VERBOSE_LIFE("Initialized");
}

/// Organism update routine                                                   
///   @param deltaTime - time between updates                                 
///   @return false                                                           
bool Organism::Update(Time deltaTime) {
   //TODO
   return false;
}

/// React on environmental change                                             
void Organism::Refresh() {

}