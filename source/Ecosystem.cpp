///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#include "Ecosystem.hpp"
#include "Life.hpp"


/// Ecosystem construction                                                    
///   @param producer - the system producer                                   
///   @param descriptor - instructions for configuring the ecosystem          
Ecosystem::Ecosystem(InputSDL* producer, const Neat& descriptor)
   : Resolvable   {this}
   , ProducedFrom {producer, descriptor}
   , mOrganisms   {this} {
   VERBOSE_LIFE("Initializing...");
   Couple(descriptor);
   VERBOSE_LIFE("Initialized");
}

/// Shutdown the module                                                       
Ecosystem::~Ecosystem() {

}

/// Produce GUI elements in the system                                        
///   @param verb - creation verb to satisfy                                  
void Ecosystem::Create(Verb& verb) {
   mOrganisms.Create(verb);
}

/// React on environmental change                                             
void Ecosystem::Refresh() {

}
