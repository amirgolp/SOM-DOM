/*---------------------------------------------------------------------------*\

License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::reactingWallFvPatchScalarField

Description
    Set surface concentration for boundaries on a reacting wall

SourceFiles
    reactingWallFvPatchScalarField.C

\*---------------------------------------------------------------------------*/

#ifndef reactingWallFvPatchScalarField_H
#define reactingWallFvPatchScalarField_H

#include "fvPatchFields.H"
#include "fixedValueFvPatchFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                  Class reactingWallFvPatch Declaration
\*---------------------------------------------------------------------------*/

class reactingWallFvPatchScalarField
:
    public fixedValueFvPatchScalarField
{

	wordList surfaceMasters_;
	scalarList density_;

	void initialize();

public:

    //- Runtime type information
    TypeName("reactingWall");


    // Constructors

        //- Construct from patch and internal field
        reactingWallFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        reactingWallFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given
        //  reactingWallFvPatchScalarField onto a new patch
        reactingWallFvPatchScalarField
        (
            const reactingWallFvPatchScalarField&,
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const fvPatchFieldMapper&
        );

        //- Construct as copy
        reactingWallFvPatchScalarField
        (
            const reactingWallFvPatchScalarField&
        );

        //- Construct and return a clone
        virtual tmp<fvPatchScalarField> clone() const
        {
            return tmp<fvPatchScalarField>
            (
                new reactingWallFvPatchScalarField(*this)
            );
        }

        //- Construct as copy setting internal field reference
        reactingWallFvPatchScalarField
        (
            const reactingWallFvPatchScalarField&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual tmp<fvPatchScalarField> clone
        (
            const DimensionedField<scalar, volMesh>& iF
        ) const
        {
            return tmp<fvPatchScalarField>
            (
                new reactingWallFvPatchScalarField(*this, iF)
            );
        }


    // Member functions

		//get surface master list
		const wordList& get_surface_masters() const
		{
			return surfaceMasters_;
		}

		//get surface master list
		const scalarList& get_density() const
		{
			return density_;
		}

        //- Write
        virtual void write(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
