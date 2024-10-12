import React, { useState, useEffect } from 'react';
import axios from 'axios';
import { useInfiniteQuery } from 'react-query';
import { Folder } from '/src/components/Folder.jsx';
import { File } from '/src/components/File.jsx';

import PDF from '/src/images/pdf.png';
import CODE from '/src/images/code.png';
import CSV from '/src/images/csv.png';
import DOSSIER_OUVERT from '/src/images/dossier_ouvert.png';
import DOSSIER_FERME from '/src/images/dossier_ferme.png';
import FICHIER from '/src/images/fichier.png';
import FLECHE from '/src/images/fleche_retour.png';
import ZIP from '/src/images/zip.png';

const FileExplorer = ({ owner, repo, branch }) => {
    // URL API GitHub.
    const formatGitHubUrl = (path) => {
        return `https://github.com/${owner}/${repo}/blob/${branch}/Cours`;
    };

    // Fonction pour récupérer 50 fichiers/dossiers à la fois
    const fetchTree = async ({ pageParam = 0 }) => {
        const response = await axios.get(
            `https://api.github.com/repos/${owner}/${repo}/git/trees/${branch}?recursive=1`
        );
        const allTree = response.data.tree;
        const startIndex = pageParam * 50;
        const endIndex = startIndex + 50;
        return {
            data: allTree.slice(startIndex, endIndex),
            nextPage: endIndex < allTree.length ? pageParam + 1 : undefined, // Pagination
        };
    };

    // Scroll infinie.
    const {
        data,
        fetchNextPage,
        hasNextPage,
        isFetchingNextPage,
        isLoading,
    } = useInfiniteQuery(['treeData', branch], fetchTree, {
        getNextPageParam: (lastPage) => lastPage.nextPage,
    });

    // Regarder le niveau du scroll dans la page
    useEffect(() => {
        const handleScroll = () => {
            if (window.innerHeight + window.scrollY >= document.body.offsetHeight - 100 && hasNextPage) {
                fetchNextPage(); // Charger plus de fichiers si on atteint le bas de la page
            }
        };
        window.addEventListener('scroll', handleScroll);
        return () => window.removeEventListener('scroll', handleScroll);
    }, [hasNextPage, fetchNextPage]);

    // Image par défaut pour les dossiers et fichiers
    const folderImage = DOSSIER_FERME;

    // Fonction pour déterminer l'image à afficher en fonction de l'extension
    const getFileImage = (fileName) => {
        const extension = fileName.split('.').pop().toLowerCase(); // Extraire l'extension

        // Retourner la bonne image en fonction de l'extension.
        switch (extension) {
            case 'pdf':
                return PDF;
            case 'csv':
                return CSV;
            case 'zip':
                return ZIP;
            case 'js':
            case 'jsx':
            case 'html':
            case 'css':
            case 'json':
            case 'c':
            case 'php':
            case 'md':
                return CODE;
            default:
                return FICHIER; // Image par défaut si l'extension n'est pas reconnue
        }
    };

    // Affichage finale des fichiers et dossiers
    const renderTree = (tree) => {
        return tree.map((item) => {
            // Juste le nom du fichiers ou dossiers
            const name = item.path.split('/').pop();

            return (
                <div key={item.sha}>
                    {item.type === 'tree' ? (
                        <Folder name={name} image={folderImage} />
                    ) : (
                        <File name={name} image={getFileImage(name)} />
                    )}
                </div>
            );
        });
    };

    return (
        <div>
            {isLoading ? (
                <p>Chargement de mes fichiers...</p>
            ) : (
                <>
                    {data.pages.map((page, index) => (
                        <div key={index}>{renderTree(page.data)}</div>
                    ))}
                    {isFetchingNextPage && <p>Chargement de plus de fichiers...</p>}
                </>
            )}
        </div>
    );
};

export default FileExplorer;
