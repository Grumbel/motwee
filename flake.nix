 {
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";

    tinycmmc.url = "github:grumbel/tinycmmc";
    tinycmmc.inputs.nixpkgs.follows = "nixpkgs";
    tinycmmc.inputs.flake-utils.follows = "flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, tinycmmc }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in rec {
        packages = rec {
          default = motwee;

          motwee = pkgs.stdenv.mkDerivation {
            pname = "motwee";
            version = "0.0.0";

            src = ./.;

            cmakeFlags = [
              "-DBUILD_EXTRA=ON"
            ];

            nativeBuildInputs = with pkgs; [
              cmake
            ];

            buildInputs = [
              tinycmmc.packages.${system}.default
            ];
          };
        };
      }
    );
}
