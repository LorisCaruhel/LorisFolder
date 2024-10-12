import React, { useState, useEffect } from 'react';
import axios from 'axios';
import { useInfiniteQuery } from 'react-query';
import { Folder } from '/src/components/Folder.jsx';
import { File } from '/src/components/File.jsx';

import PDF from '/src/images/pdf.png';
import CSV from '/src/images/csv.png';
import DOSSIER_OUVERT from '/src/images/dossier_ouvert.png';
import DOSSIER_FERME from '/src/images/dossier_ferme.png';
import FICHIER from '/src/images/fichier.png';
import FLECHE from '/src/images/fleche_retour.png';
import ZIP from '/src/images/zip.png';
import IMAGE from '/src/images/image.png';
import DOCS from '/src/images/docs.png';
import DIAPO from '/src/images/diaporama.png';
import BINAIRE from '/src/images/binaire.png';
import BASH from '/src/images/Bash-Dark.svg';
import C from '/src/images/C.svg';
import CSS from '/src/images/CSS.svg';
import HTML from '/src/images/HTML.svg';
import JAVA from '/src/images/Java-Dark.svg';
import JS from '/src/images/JavaScript.svg';
import JSON from '/src/images/json.png';
import MD from '/src/images/Markdown-Dark.svg';
import PHP from '/src/images/PHP-Dark.svg';
import SQL from '/src/images/PostgreSQL-Dark.svg';
import PYTHON from '/src/images/Python-Dark.svg';
import REACT from '/src/images/React-Dark.svg';
import SASS from '/src/images/Sass.svg';
import TS from '/src/images/TypeScript.svg';

import {Button} from "/src/components/Button.jsx";

const FileExplorer = ({ owner, repo, branch }) => {
    const [currentPath, setCurrentPath] = useState(''); // Chemin courant
    const [history, setHistory] = useState([]); // Historique des chemins parcourus

    // URL API GitHub
    const formatGitHubUrl = (path) => {
        return `https://github.com/${owner}/${repo}/blob/${branch}/${path}`;
    };

    // Fonction pour récupérer tous les fichiers/dossiers
    const fetchTree = async () => {
        const response = await axios.get(
            `https://api.github.com/repos/${owner}/${repo}/git/trees/${branch}?recursive=1`
        );
        return response.data.tree;
    };

    // Scroll infini
    const { data, isLoading } = useInfiniteQuery('treeData', fetchTree);

    // Gérer les dossiers cliqués pour navigation
    const handleFolderClick = (folderPath) => {
        setHistory((prev) => [...prev, currentPath]); // Ajouter le chemin actuel à l'historique
        setCurrentPath(folderPath); // Mettre à jour le chemin courant
    };

    // Gérer le retour en arrière
    const handleBackClick = () => {
        setCurrentPath(history[history.length - 1] || ''); // Retourner au dernier chemin
        setHistory((prev) => prev.slice(0, prev.length - 1)); // Retirer le dernier chemin de l'historique
    };

    // Filtrer les fichiers/dossiers en fonction du chemin courant
    const filterTreeByCurrentPath = (tree) => {
        return tree.filter((item) => {
            const pathParts = item.path.split('/');
            const folderParts = currentPath.split('/');

            // Affiche les éléments dans le chemin courant ou les sous-éléments immédiats
            if (currentPath === '') {
                return pathParts.length === 1; // Afficher les éléments racine
            }

            return (
                pathParts.slice(0, folderParts.length).join('/') === currentPath &&
                pathParts.length === folderParts.length + 1
            );
        });
    };

    // Déterminer l'image à afficher en fonction de l'extension
    const getFileImage = (fileName) => {
        const extension = fileName.split('.').pop().toLowerCase(); // Extraire l'extension

        switch (extension) {
            case 'out':
                return BINAIRE;
            case 'pptx':
            case 'ppt':
                return DIAPO;
            case 'png':
            case 'jpg':
            case 'jpeg':
            case 'webp':
            case 'svg':
                return IMAGE;
            case 'pdf':
                return PDF;
            case 'xlsx':
            case 'csv':
                return CSV;
            case 'rar':
            case 'zip':
                return ZIP;
            case 'docx':
            case 'odt':
                return DOCS;
            case 'js':
                return JS;
            case 'jsx':
                return REACT;
            case 'html':
                return HTML;
            case 'css':
                return CSS;
            case 'json':
                return JSON;
            case 'c':
                return C;
            case 'php':
                return PHP;
            case 'java':
                return JAVA;
            case 'sql':
                return SQL;
            case 'md':
                return MD;
            case 'sh':
            case 'bash':
                return BASH;
            case 'scss':
                return SASS;
            case 'ts':
                return TS;
            case 'py':
                return PYTHON;
            default:
                return FICHIER;
        }
    };

    // Affichage finale des fichiers et dossiers
    const renderTree = (tree) => {
        const filteredTree = filterTreeByCurrentPath(tree); // Filtrer selon le chemin courant
        return filteredTree.map((item) => {
            const name = item.path.split('/').pop(); // Juste le nom du fichier ou dossier

            return (
                <div key={item.sha}>
                    {item.type === 'tree' ? (
                        <Folder
                            name={name}
                            image={DOSSIER_FERME}
                            onClick={() => handleFolderClick(item.path)}
                        />
                    ) : (
                        <File name={name} image={getFileImage(name)} path={item.path} />
                    )}
                </div>
            );
        });
    };

    return (
        <div>
            {currentPath && (
                <Button path={currentPath} image={FLECHE} handleBackClick={handleBackClick} />
            )}
            {isLoading ? (
                <p>Chargement de mes fichiers...</p>
            ) : (
                <div>
                    {renderTree(data?.pages[0] || [])}
                </div>
            )}
        </div>
    );
};

export default FileExplorer;
