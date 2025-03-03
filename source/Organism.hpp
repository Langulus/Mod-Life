///                                                                           
/// Langulus::Module::Life                                                    
/// Copyright (c) 2024 Dimo Markov <team@langulus.com>                        
/// Part of the Langulus framework, see https://langulus.com                  
///                                                                           
/// SPDX-License-Identifier: GPL-3.0-or-later                                 
///                                                                           
#pragma once
#include "Common.hpp"
#include <Langulus/Flow/Producible.hpp>


///                                                                           
///   Organism                                                                
///                                                                           
/// An animal, plant, or bacteria - a functional part of an ecosystem.        
///                                                                           
struct Organism final : A::Organism, ProducedFrom<Ecosystem> {
   LANGULUS(ABSTRACT) false;
   LANGULUS(PRODUCER) Ecosystem;
   LANGULUS_BASES(A::Organism);

private:
   // A private hierarchy of organs and tissues                         
   // These will get spilled when the organism dies and can no longer   
   // maintain filtering the verbs (a.k.a. homeostasis).                
   Thing mAnatomy;

public:
   Organism(Ecosystem*, const Many&);

   bool Update(Time);
   void Refresh();
};