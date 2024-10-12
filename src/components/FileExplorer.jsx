import React, { useState } from 'react';
import axios from 'axios';
import { useQuery } from 'react-query';
import { Folder } from '/src/components/Folder.jsx';
import { File } from '/src/components/File.jsx';

import PDF from '/src/images/pdf.png';
import CSV from '/src/images/csv.png';
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

import { Button } from '/src/components/Button.jsx';

const FileExplorer = ({ owner, repo, branch }) => {
    const [currentPath, setCurrentPath] = useState('Cours'); // On commence dans le répertoire 'Cours'
    const [history, setHistory] = useState([]); // Historique des chemins parcourus

    // Fonction pour récupérer l'arborescence des fichiers depuis l'API GitHub
    const fetchTree = async () => {
        const response = await axios.get(
            `https://api.github.com/repos/${owner}/${repo}/git/trees/${branch}?recursive=1`
        );
        return response.data.tree;
    };

    // Utilisation de useQuery pour appeler l'API GitHub
    const { data, isLoading } = useQuery('treeData', fetchTree);

    // Gestion du clic sur un dossier
    const handleFolderClick = (folderPath) => {
        setHistory((prev) => [...prev, currentPath]); // Ajouter le chemin actuel à l'historique
        setCurrentPath(folderPath); // Mettre à jour le chemin courant
    };

    // Gestion du clic retour
    const handleBackClick = () => {
        if (history.length > 0) {
            const previousPath = history[history.length - 1]; // Dernier chemin parcouru
            setCurrentPath(previousPath); // Mettre à jour avec le chemin précédent
            setHistory((prev) => prev.slice(0, prev.length - 1)); // Enlever le dernier chemin de l'historique
        }
    };

    // Modification : fonction pour formater les URLs GitHub pour les fichiers depuis la branche "main"
    const formatGitHubUrl = (path) => {
        return `https://github.com/${owner}/${repo}/blob/main/${path}`; // Pointage vers la branche "main"
    };

    // Filtrage des fichiers/dossiers en fonction du chemin courant
    const filterTreeByCurrentPath = (tree) => {
        return tree.filter((item) => {
            const pathParts = item.path.split('/');
            const folderParts = currentPath.split('/');

            if (currentPath === 'Cours') {
                // Afficher seulement les éléments directement sous 'Cours'
                return pathParts[0] === 'Cours' && pathParts.length === 2;
            }

            // Afficher les éléments dans le chemin courant ou les sous-éléments immédiats
            return (
                pathParts[0] === 'Cours' &&
                pathParts.slice(0, folderParts.length).join('/') === currentPath &&
                pathParts.length === folderParts.length + 1
            );
        });
    };

    // Fonction pour afficher les fichiers et dossiers filtrés
    const renderTree = (tree) => {
        const filteredTree = filterTreeByCurrentPath(tree);
        return filteredTree.map((item) => {
            const name = item.path.split('/').pop(); // Obtenir le nom du fichier ou dossier

            return (
                <div key={item.sha}>
                    {item.type === 'tree' ? (
                        <Folder
                            name={name}
                            image={DOSSIER_FERME}
                            onClick={() => handleFolderClick(item.path)}
                        />
                    ) : (
                        <File
                            name={name}
                            image={getFileImage(name)}
                            path={formatGitHubUrl(item.path)} // Utilisation de formatGitHubUrl pour générer le lien correct
                        />
                    )}
                </div>
            );
        });
    };

    // Fonction pour déterminer l'image du fichier en fonction de son extension
    const getFileImage = (fileName) => {
        const extension = fileName.split('.').pop().toLowerCase();

        switch (extension) {
            case 'out': return BINAIRE;
            case 'pptx': case 'ppt': return DIAPO;
            case 'png': case 'jpg': case 'jpeg': case 'webp': case 'svg': return IMAGE;
            case 'pdf': return PDF;
            case 'xlsx': case 'csv': return CSV;
            case 'rar': case 'zip': return ZIP;
            case 'docx': case 'odt': return DOCS;
            case 'js': return JS;
            case 'jsx': return REACT;
            case 'html': return HTML;
            case 'css': return CSS;
            case 'json': return JSON;
            case 'c': return C;
            case 'php': return PHP;
            case 'java': return JAVA;
            case 'sql': return SQL;
            case 'md': return MD;
            case 'sh': case 'bash': return BASH;
            case 'scss': return SASS;
            case 'ts': return TS;
            case 'py': return PYTHON;
            default: return FICHIER;
        }
    };

    return (
        <div>
            {history.length > 0 && ( // Afficher le bouton retour si l'historique n'est pas vide
                <Button path={currentPath} image={FLECHE} onClick={handleBackClick} />
            )}
            {isLoading ? (
                <p>Chargement de mes fichiers...</p>
            ) : (
                <div>{renderTree(data || [])}</div>
            )}
        </div>
    );
};

export default FileExplorer;
