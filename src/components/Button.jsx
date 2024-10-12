import React from 'react';

/**
 * @param {string} image - L'image du bouton retour
 * @param {function} onClick - La fonction appelée lors du clic
 * @returns {JSX.Element}
 */
export const Button = ({ path, image, onClick }) => {
    return (
        <button onClick={onClick}>
            <img src={image} alt="Retour" />
            <p>{path}</p>
        </button>
    );
};