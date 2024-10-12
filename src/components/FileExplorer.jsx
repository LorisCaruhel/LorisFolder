import React, { useState, useEffect } from 'react';
import axios from 'axios';
import { useInfiniteQuery } from 'react-query';
import { Folder } from '/src/components/Folder.jsx';
import { File } from '/src/components/File.jsx';

const FileExplorer = ({ owner, repo, branch }) => {
    // Fonction pour formater l'URL GitHub
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

    // Utilisation de React Query avec la pagination infinie
    const {
        data,
        fetchNextPage,
        hasNextPage,
        isFetchingNextPage,
        isLoading,
    } = useInfiniteQuery(['treeData', branch], fetchTree, {
        getNextPageParam: (lastPage) => lastPage.nextPage,
    });

    // Fonction pour écouter le scroll et charger plus de fichiers
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
    const folderImage = 'path/to/folder-icon.png'; // Image pour les dossiers
    const fileImage = 'path/to/file-icon.png';     // Image pour les fichiers

    // Génère l'affichage de l'arborescence des fichiers/dossiers
    const renderTree = (tree) => {
        return tree.map((item) => (
            <div key={item.sha}>
                {item.type === 'tree' ? (
                    // Utilisation du composant Folder pour les dossiers
                    <Folder name={item.path} image={folderImage} />
                ) : (
                    // Utilisation du composant File pour les fichiers
                    <File name={item.path} image={fileImage} />
                )}
            </div>
        ));
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
