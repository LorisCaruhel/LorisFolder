/**
 *
 * @param {string} name
 * @param {string} image
 * @param {string} path
 * @param {function} onClick
 * @returns {JSX.Element}
 * @constructor
 */
export function Folder({ name, image, path, onClick, ...props }) {
    return (
        <div className="folder" onClick={onClick} {...props} style={{ cursor: 'pointer' }}>
            <img src={image} alt={name} />
            <span>{name}</span>
        </div>
    );
}
