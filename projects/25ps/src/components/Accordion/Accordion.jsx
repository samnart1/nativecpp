import React, { useState } from 'react'
import data from './data'

const Accordion = () => {
  const [selected, setSelected] = useState(null)

  const handleSelected = (id) => {
    setSelected( selected === id ? null : id)
  }

  return (
    <div>
      <div>
        {data && data.length > 0 ? (
          data.map((item) => (
            <div>
              <div onClick={() => handleSelected(item.id)}>
                <h3>{item.question}</h3>
                <span>+</span>
              </div>
              {selected === item.id ? <div>{item.answer}</div> : null}
            </div>
          ))
        ) : (
          <div>No Data Found!!!</div>
        )}
      </div>
    </div>
  )
}

export default Accordion
