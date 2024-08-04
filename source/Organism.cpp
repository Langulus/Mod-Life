///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "Organism.hpp"
#include "Life.hpp"


/// Listener construction                                                     
///   @param producer - the producer                                          
///   @param descriptor - instructions for configuring the organism           
Organism::Organism(Ecosystem* producer, const Neat& descriptor)
   : Resolvable   {this}
   , ProducedFrom {producer, descriptor} {
   VERBOSE_LIFE("Initializing...");
   Couple(descriptor);
   VERBOSE_LIFE("Initialized");
}

/// React on environmental change                                             
void Organism::Refresh() {

}