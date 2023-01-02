//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "SampleMeshGenerator.h"
#include "CastUniquePointer.h"
#include "libmesh/node.h"

registerMooseObject("MooseApp", SampleMeshGenerator);

InputParameters
SampleMeshGenerator::validParams()
{
  InputParameters params = MeshGenerator::validParams();

  params.addRequiredParam<MeshGeneratorName>("input", "Input mesh to Move");

  // Add parameters like this:
  // params.addRequiredParam<param_C++_type>("param_name", "Parameter description");

  params.addClassDescription("Modifies the mesh in some way");

  return params;
}

SampleMeshGenerator::SampleMeshGenerator(const InputParameters & parameters)
  : MeshGenerator(parameters),
    _input(getMesh("input"))
{
  // Initialize class members
  // Do some parameter checking to prevent user from passing nonsense
}

std::unique_ptr<MeshBase>
SampleMeshGenerator::generate()
{
  std::unique_ptr<MeshBase> mesh = std::move(_input);

  // Do things on the mesh
  // See doxygen for MeshBase to see all the operations available!

  return dynamic_pointer_cast<MeshBase>(mesh);
}
