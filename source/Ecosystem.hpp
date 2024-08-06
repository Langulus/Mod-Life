///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Organism.hpp"


///                                                                           
///   Ecosystem                                                               
///                                                                           
/// A place where organisms interact with each other and the world.           
///                                                                           
struct Ecosystem final : A::Unit, ProducedFrom<Life> {
   LANGULUS(ABSTRACT) false;
   LANGULUS(PRODUCER) Life;
   LANGULUS_BASES(A::Unit);
   LANGULUS_VERBS(Verbs::Create);

private:
   // List of participating organisms                                   
   TFactory<Organism> mOrganisms;

public:
   Ecosystem(Life*, const Neat&);
   ~Ecosystem();

   void Create(Verb&);
   void Refresh();
};